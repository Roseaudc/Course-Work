<?php
include "dbconnect.php";
$sql = "delete from championship where id = " .  $_REQUEST["id"] ;

myquery($mysqli,$sql);

?>
<script>
window.location='listChampionships.php';
</script>