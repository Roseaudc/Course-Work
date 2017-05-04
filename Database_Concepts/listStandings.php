<?php
include "menu.php";
?>
<table border=1>
<tr>
<th>Team Name</th>
<th>Wins</th>
<th>Losses</th>
</tr>
<?php
include "dbconnect.php";
$sql = "select * from standings order by wins DESC";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['name'] . '</td>';
  echo '<td>' . $row['wins'] . '</td>';
  echo '<td>' . $row['losses'] . '</td>';
  echo "<td><a href='delStandingssrv.php?id=" . $row['id'] ."'>Del</a> ";
  echo "<a href='editStandingsclt.php?id=" . $row['id']   ."'>Edit</a></td>";
  echo "</tr>";
}
?>
</table>