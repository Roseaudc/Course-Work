<?php
include "dbconnect.php";
$sql = "insert into coach (name, team, contract) values('" .
  $_REQUEST["name"] . "','" .
  $_REQUEST["team"] . "','" .
  $_REQUEST["contract"] . "')";

myquery($mysqli,$sql);

?>
<script>
window.location='listCoaches.php';
</script>