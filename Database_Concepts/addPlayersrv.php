<?php
include "dbconnect.php";
           
  $name = $_REQUEST["name"];
  $number = $_REQUEST["number"];
  $position = $_REQUEST["position"];
  $team = $_REQUEST["team"];
        
  $sql = "call controlDepth('$name', $number, '$position', '$team', @x)";
  
  myquery($mysqli,$sql);
   
  $sql = "SELECT @x status";

  $result = myquery($mysqli,$sql);

  $row = $result->fetch_assoc();
  if($row["status"] == "Too many players") 
   echo "THE ROSTER IS FULL!!!";
  else
   echo "<script>window.location='listPlayers.php'</script>";
?>