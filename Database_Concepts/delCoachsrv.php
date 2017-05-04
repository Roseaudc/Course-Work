<?php
include "dbconnect.php";
$sql = "delete from coach where id = " .  $_REQUEST["id"] ;

myquery($mysqli,$sql);

?>
<script>
window.location='listCoaches.php';
</script>