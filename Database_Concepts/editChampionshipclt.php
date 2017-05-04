<?php
include "dbconnect.php";
$sql = "select * from coach where id = '" . $_REQUEST["id"] ."';";

$result = myquery($mysqli,$sql);

$row = $result->fetch_assoc();
?>
<form action="editChampionshipsrv.php" method="get">
</br>

<input type="hidden" name="id" value="<?php echo $_REQUEST['id']; ?>"/>

<table>
<form action="addChampionshipsrv.php" method="get">

<tr>
<td>
Team Name:</td><td><input type="text" name = "team"/>
</td>
</tr>

<tr>
<td>
Year:</td><td><input type="text" name="year"/>
</td>
</tr>

<tr>
<td>
Final's MVP:</td><td><input type="text" name="mvp"/>
</td>
</tr>


<tr>
<td>
<input type="submit"/>
</td>
</tr>
</form>
</table>