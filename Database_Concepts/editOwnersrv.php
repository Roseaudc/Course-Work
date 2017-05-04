<?php
require 'dbconnect.php';
$sql = "update owner "; 

$sql .= "set name = '" . $_REQUEST["name"] . "', "; 
$sql .= "team = '" . $_REQUEST["team"] . "'";
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
window.location = 'listOwners.php';
</script>