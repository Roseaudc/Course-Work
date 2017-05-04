<?php
include "menu.php";
?>
<table border=1>

<tr>
<th>Owner's Name</th>
<th>Team Owned</th>

</tr>
<?php
include "dbconnect.php";
$sql = "select * from owner order by name";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['name'] . '</td>';
  echo '<td>' . $row['team'] . '</td>';
  echo "<td><a href='delOwnersrv.php?id=" . $row['id'] ."'>Del</a> ";
  echo "<a href='editOwnerclt.php?id=" . $row['id']   ."'>Edit</a></td>";
  echo "</tr>";
}
?>
</table>
<a href="addOwnerclt.php">Add New Owner</a>