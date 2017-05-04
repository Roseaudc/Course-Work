<?php
include "dbconnect.php";
$sql = "delete from player where id = " .  $_REQUEST["id"] ;

myquery($mysqli,$sql);

?>
<script>
window.location='listPlayers.php';
</script>