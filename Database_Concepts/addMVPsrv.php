<?php
include "dbconnect.php";
$sql = "insert into MVP (name, points, assists, rebounds, team, year) values('" .
  $_REQUEST["name"] . "','" .
  $_REQUEST["points"] . "','" .
  $_REQUEST["assists"] . "','" .
  $_REQUEST["rebounds"] . "','" .
  $_REQUEST["team"] . "','" .
  $_REQUEST["year"] . "')";

myquery($mysqli,$sql);

?>
<script>
window.location='listMVPS.php';
</script>