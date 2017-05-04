<?php
require 'dbconnect.php';
$sql = "update championship "; 

$sql .= "set year = '" . $_REQUEST["year"] . "', "; 
$sql .= "team = '" . $_REQUEST["team"] . "', ";  
$sql .= "mvp = '" . $_REQUEST["mvp"] . "'";
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
window.location = 'listChampionships.php';
</script>