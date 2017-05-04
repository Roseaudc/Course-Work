<?php
require 'dbconnect.php';
$sql = "update standings "; 

$sql .= "set wins = '" . $_REQUEST["wins"] . "', ";   
$sql .= "losses = '" . $_REQUEST["losses"] . "'";
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
window.location = 'listStandings.php';
</script>