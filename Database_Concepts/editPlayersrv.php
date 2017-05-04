<?php
require 'dbconnect.php';
$sql = "update player "; 

$sql .= "set team = '" . $_REQUEST["team"] . "', "; 
$sql .= "position = '" . $_REQUEST["position"] . "', "; 
$sql .= "number = '" . $_REQUEST["number"] . "', "; 
$sql .= "name = '" . $_REQUEST["name"] . "'";
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
window.location = 'listPlayers.php';
</script>