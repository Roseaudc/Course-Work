#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "sniffex.h"

int main(int argc, char **argv) {
  
  char* inet;
  char* host;
  char* netmask;
  char* dev;
  const char* device;
  int error_code;
  int lookup_returnCode;
  
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_if_t *alldevs, *d;
  
  bpf_u_int32 netp; /* ip */
  bpf_u_int32 maskp;/* subnet mask */
  
  struct in_addr addr;
  std::vector<std::string> ndevs;
  std::vector<char*> inets;
  
  /**
   * 
   * Ask the user to select a network device on the
   * host machine.
   * 
   */
  
  if ( pcap_findalldevs( &alldevs, errbuf ) == -1 ) {
    
    std::cerr<<"Error in pcap_findalldevs: "<< errbuf<< std::endl;
    exit(1);
    
  }
  
  int i = 0;
  int selected_dev = 0;
  
  std::cout<< "------------------------------------------"<< std::endl;
  std::cout<<"List of available network devices:"<<std::endl;
  std::cout<< "------------------------------------------"<< std::endl;
  
  for ( d=alldevs; d; d=d->next ) {
    
    ndevs.push_back( d->name );
    
    
    inet = (char*)malloc(16);
    inet[0] = '\0';
   
    for ( pcap_addr_t *a=d->addresses; a!=NULL; a=a->next ) {
      if (a->addr->sa_family == AF_INET )   
	strncat(inet, inet_ntoa( ( ( struct sockaddr_in* )a->addr )->sin_addr ), 16 );
    }
    
    inets.push_back( inet );
    
    std::cout<<"("<<(i)<<") "<<ndevs[i++]<<" ";
    
    if ( d->description )
      std::cout<<"\t\""<<d->description<<"\""<<std::endl;
    else
      std::cout<<""<< std::endl;
      
  }
  
  std::cout<< "------------------------------------------"<< std::endl;
  std::cout<<"Please select a device [1 through "<<i<<"]: ";
  std::cin>>selected_dev;
  std::cout<<"Selected device: "<<ndevs[selected_dev-1]<<std::endl;

  /*
	TODO: 1

	Use pcap_lookupnet function to find network number
	and mask for the selected device.
	

	http://linux.die.net/man/3/pcap_lookupnet
  */
device = ndevs[selected_dev - 1].c_str();
pcap_lookupnet(device, &netp, &maskp, (char*)errbuf);

  /*
	TODO: 2

	Display host, inet, and mask information

	for the selected device.

	Hints:
	 1. use inet_ntoa to find host info.
	 2. use netp and maskp (found above) to display inet
	    and netmask info.

	http://linux.die.net/man/3/inet_ntoa
  */
addr.s_addr = netp;
printf("Host = %s\n", inet_ntoa(addr));

printf("Inet: %s\n", inets[selected_dev - 1]);

addr.s_addr = maskp;
printf("Mask = %s\n",inet_ntoa(addr));

  
  for ( int i=0; i<inets.size(); i++ ) free( inets[i] ); 
  
  /**
   * 
   * Live packet capture
   * 
   * 
   */
   
  std::cout<< "Starting live packet capture!"<<std::endl;
 
  const u_char* packet;
  struct pcap_pkthdr hdr;
  struct sniff_ethernet* eth_hdr;
  int sport;
  int dport;
  pcap_t* cap_desc;

  struct timespec nano_time_spec;
  nano_time_spec.tv_nsec=100000;
  nano_time_spec.tv_sec=0;

  /*
	TODO: 3

	Start live packet capture using pcap_open_live function.

	http://linux.die.net/man/3/inet_ntoa

  */
  cap_desc = pcap_open_live(device,BUFSIZ,true,nano_time_spec.tv_nsec,errbuf);




  
  while ( true ) {
  
    packet = pcap_next( cap_desc, &hdr ); 
  
    if ( packet != NULL ) {

      /*
	TODO: 4

	For each packet inspect the headers as follows:
		1. Get the ETHERNET frame
                2. Get the IP datagram
		3. Get the TCP segment
	        2. If the ether_type == ETHERTYPE_IP AND the ip_p == IPPROTO_TCP then
		   display the sender and receiver info if either has port = 80.

      */
      
	eth_hdr = (struct sniff_ethernet *) packet;
	if(ntohs(eth_hdr -> ether_type) == ETHERTYPE_IP)
	{
		struct sniff_ip* ip_hdr = (struct sniff_ip*) (packet + SIZE_ETHERNET);
		if(ip_hdr -> ip_p == IPPROTO_TCP)
		{
			u_int ip_len = IP_HL(ip_hdr) * 4;
			struct sniff_tcp* tcp_hdr = (struct sniff_tcp*) (packet + SIZE_ETHERNET + ip_len);
			if (ntohs(tcp_hdr->th_sport) == 80 || ntohs(tcp_hdr->th_dport) == 80)
			{
				printf("Source: [%s : %d] ->",inet_ntoa(ip_hdr->ip_src), ntohs(tcp_hdr->th_sport));
				printf("Destination: [%s : %d]\n", inet_ntoa(ip_hdr->ip_dst),ntohs(tcp_hdr->th_dport));
			}
		}
	}
	
     
    }
  
  } 
  
  return 0;

} 
