<?php
include "dbconnect.php";
$sql = "select * from team where id = '" . $_REQUEST["id"] ."';";

$result = myquery($mysqli,$sql);

$row = $result->fetch_assoc();
?>
<form action="editTeamsrv.php" method="get">
</br>

<input type="hidden" name="id" value="<?php echo $_REQUEST['id']; ?>"/>

<table>
<form action="addTeamsrv.php" method="get">

<tr>
<td>
Team Name:</td><td><input type="text" name = "name"/>
</td>
</tr>

<tr>
<td>
Rank:</td><td><input type="text" name="rank"/>
</td>
</tr>

<tr>
<td>
Conference:</td><td><input type="text" name="conference"/>
</td>
</tr>


<tr>
<td>
<input type="submit"/>
</td>
</tr>
</form>
</table>