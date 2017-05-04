<?php
include "dbconnect.php";
$sql = "select * from player where id = '" . $_REQUEST["id"] ."';";

$result = myquery($mysqli,$sql);

$row = $result->fetch_assoc();
?>
<form action="editPlayersrv.php" method="get">
</br>
<input type="hidden" name="id" value="<?php echo $_REQUEST['id']; ?>"/>

<table>
<form action="addPlayersrv.php" method="get">

<tr>
<td>
Name:</td><td><input type="text" name="name"/>
</td>
</tr>

<tr>
<td>
Number:</td><td><input type="text" name="number"/>
</td>
</tr>

<tr>
<td>
Position:</td><td><input type="text" name="position"/>
</td>
</tr>

<tr>
<td>
Team:</td><td><input type="text" name="team"/>
</td>
</tr>

<tr>
<td>
<input type="submit"/>
</td>
</tr>
</form>
</table>