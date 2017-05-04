<?php
include "dbconnect.php";
$sql = "delete from standings where id = " .  $_REQUEST["id"] ;

myquery($mysqli,$sql);

?>
<script>
window.location='listStandings.php';
</script>