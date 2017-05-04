<?php
include "menu.php";
?>
<table border=1>
<tr>
<th>Name</th>
<th>Number</th>
<th>Position</th>
<th>Team</th>
</tr>
<?php
include "dbconnect.php";
$sql = "select * from player order by team, name";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['name'] . '</td>';
  echo '<td>' . $row['number'] . '</td>';
  echo '<td>' . $row['position'] . '</td>';
  echo '<td>' . $row['team'] . '</td>';
  echo "<td><a href='delPlayersrv.php?id=" . $row['id'] ."'>Del</a> ";
  echo "<a href='editPlayerclt.php?id=" . $row['id']   ."'>Edit</a></td>";
  echo "</tr>";
}
?>
</table>
<a href="addPlayerclt.php">Add New</a>