
<?php
include "dbconnect.php";
$sql = "select * from owner where id = '" . $_REQUEST["id"] ."';";

$result = myquery($mysqli,$sql);

$row = $result->fetch_assoc();
?>
<form action="editOwnersrv.php" method="get">
</br>

<input type="hidden" name="id" value="<?php echo $_REQUEST['id']; ?>"/>

<table>
<form action="addOwnersrv.php" method="get">

<tr>
<td>
Owner's Name:</td><td><input type="text" name = "name"/>
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
