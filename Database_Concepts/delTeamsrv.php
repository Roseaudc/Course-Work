<?php
include "dbconnect.php";
$sql = "delete from team where id = " .  $_REQUEST["id"] ;

myquery($mysqli,$sql);

?>
<script>
window.location='listTeams.php';
</script>