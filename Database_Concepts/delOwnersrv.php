<?php
include "dbconnect.php";
$sql = "delete from owner where id = " .  $_REQUEST["id"] ;

myquery($mysqli,$sql);

?>
<script>
window.location='listOwners.php';
</script>