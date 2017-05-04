<?php
include "dbconnect.php";
$sql = "insert into owner (name, team) values('" .
  $_REQUEST["name"] . "','" .
  $_REQUEST["team"] . "')";

myquery($mysqli,$sql);

?>
<script>
window.location='listOwners.php';
</script>