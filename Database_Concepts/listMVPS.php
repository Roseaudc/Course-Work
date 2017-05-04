<?php
include "menu.php";
?>
<table border=1>
<tr>
<th>Player Name</th>
<th>PPG</th>
<th>APG</th>
<th>RPG</th>
<th>Team</th>
<th>Year</th>
</tr>
<?php
include "dbconnect.php";
$sql = "select * from MVP order by year";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['name'] . '</td>';
  echo '<td>' . $row['points'] . '</td>';
  echo '<td>' . $row['assists'] . '</td>';
  echo '<td>' . $row['rebounds'] . '</td>';
  echo '<td>' . $row['team'] . '</td>';
  echo '<td>' . $row['year'] . '</td>';
  echo "<td><a href='delMVPsrv.php?id=" . $row['id'] ."'>Del</a> ";
  echo "<a href='editMVPclt.php?id=" . $row['id']   ."'>Edit</a></td>";
  echo "</tr>";
}
?>
</table>
<a href="addMVPclt.php">Add New MVP</a>