<?php
include "dbconnect.php";
$sql = "insert into team (wins,losses) values('" .
  $_REQUEST["wins"] . "','" .
  $_REQUEST["losses"] . "')";

myquery($mysqli,$sql);

?>
<script>
window.location='listStandings.php';
</script>