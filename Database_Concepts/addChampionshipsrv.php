<?php
include "dbconnect.php";
$sql = "insert into championship (team, year, mvp) values('" .
  $_REQUEST["team"] . "','" .
  $_REQUEST["year"] . "','" .
  $_REQUEST["mvp"] . "')";

myquery($mysqli,$sql);

?>
<script>
window.location='listChampionships.php';
</script>