<?php
function myquery($mysqli,$sql) {
  if (!$result = $mysqli->query($sql)) {
    echo "Errno: " . $mysqli->errno . "</br>";
    echo "Error: " . $mysqli->error . "</br>";
    exit;
  }
  return $result;
}

$mysqli = new mysqli('127.0.0.1', 'donovan9', 'd6875870', 'donovan9_NBA');
if ($mysqli->connect_errno) {
 echo "Errno: " . $mysqli->connect_errno . "</br>";
 echo "Error: " . $mysqli->connect_error . "</br>";
 exit;
}
?>