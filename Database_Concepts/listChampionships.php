<?php
include "menu.php";
?>
<table border=1>
<tr>
<th>Team Name</th>
<th>Year</th>
<th>MVP</th>
</tr>
<?php
include "dbconnect.php";
$sql = "select * from championship order by year";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['team'] . '</td>';
  echo '<td>' . $row['year'] . '</td>';
  echo '<td>' . $row['mvp'] . '</td>';
  echo "<td><a href='delChampionshipsrv.php?id=" . $row['id'] ."'>Del</a> ";
  echo "<a href='editChampionshipclt.php?id=" . $row['id']   ."'>Edit</a></td>";
  echo "</tr>";
}
?>
</table>
<a href="addChampionshipclt.php">Add New Championship</a>