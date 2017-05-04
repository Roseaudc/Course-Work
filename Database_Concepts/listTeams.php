<?php
include "menu.php";
?>
<table border=1>
<tr>
<th>Rank</th>
<th>Team Name</th>
<th>Conference</th>
</tr>
<?php
include "dbconnect.php";
$sql = "select * from team order by rank";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['rank'] . '</td>';
  echo '<td>' . $row['name'] . '</td>';
  echo '<td>' . $row['conference'] . '</td>';
  echo "<td><a href='delTeamsrv.php?id=" . $row['id'] ."'>Del</a> ";
  echo "<a href='editTeamclt.php?id=" . $row['id']   ."'>Edit</a></td>";
  echo "</tr>";
}
?>
</table>
<a href="addTeamclt.php">Add New</a>