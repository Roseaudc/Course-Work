<?php
include "dbconnect.php";
$sql = "insert into team (name, rank, conference) values('" .
  $_REQUEST["name"] . "','" .
  $_REQUEST["rank"] . "','" .
  $_REQUEST["conference"] . "')";

myquery($mysqli,$sql);

?>
<script>
window.location='listTeams.php';
</script>