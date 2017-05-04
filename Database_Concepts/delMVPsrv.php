<?php
include "dbconnect.php";
$sql = "delete from MVP where id = " .  $_REQUEST["id"] ;

myquery($mysqli,$sql);

?>
<script>
window.location='listMVPS.php';
</script>