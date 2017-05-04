<?php
include "dbconnect.php";
$sql = "select * from standings where id = '" . $_REQUEST["id"] ."';";

$result = myquery($mysqli,$sql);

$row = $result->fetch_assoc();
?>
<form action="editStandingssrv.php" method="get">
</br>

<input type="hidden" name="id" value="<?php echo $_REQUEST['id']; ?>"/>
<input type="hidden" name="name" value="<?php echo $_REQUEST['name']; ?>"/>

<table>
<form action="addStandingssrv.php" method="get">

<tr>
<td>
Wins:</td><td><input type="text" name = "wins"/>
</td>
</tr>

<tr>
<td>
Losses:</td><td><input type="text" name="losses"/>
</td>
</tr>

<tr>
<td>
<input type="submit"/>
</td>
</tr>
</form>
</table>