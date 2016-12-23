# 
# Creates new file containing all files in the directory containing the script
# and launches in the browser
#

clear
cd "$(dirname "$realpath "$0")")"; 
ls -p | grep -v '/$' > files01.html
echo "<HTML>" | cat - files01.html > temp && mv temp files01.html
echo "</HTML>" >> files01.html
xdg-open files01.html
exit 0
