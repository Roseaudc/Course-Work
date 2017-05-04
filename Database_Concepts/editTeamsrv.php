<?php
require 'dbconnect.php';
$sql = "update team "; 

$sql .= "set name = '" . $_REQUEST["name"] . "', "; 
$sql .= "rank = '" . $_REQUEST["rank"] . "', ";  
$sql .= "conference = '" . $_REQUEST["conference"] . "'";
$sql .= "where id = '" . $_REQUEST["id"] . "';";



var_dump($sql);
if (!$result = $mysqli->multi_query($sql)) {
    echo "Error: Query error, here is why: </br>";
    echo "Errno: " . $mysqli->errno . "</br>";
    echo "Error: " . $mysqli->error . "</br>";
    exit;
}

?>

<script>
window.location = 'listTeams.php';
</script>