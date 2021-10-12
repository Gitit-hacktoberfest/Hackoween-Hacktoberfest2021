<template>
	<div class="container">
		<br />
		<br />
		<div class="row">
			<div class="col-md-6 loginRight">
				<br />
				<br />
				<div>
					<h1 class="headingText">Here is how you spend</h1>
					<h1 class="headingText">your Income</h1>
				</div>
				<br />

				<table class="table table-dark reportTable">
					<thead>
						<tr>
							<th>Category</th>
							<th>Amonunt</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<th>Book</th>
							<td>200</td>
						</tr>
						<tr>
							<th>Recharge</th>
							<td>450</td>
						</tr>
						<tr>
							<th>Grocery</th>
							<td>1000</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div class="col-md-6">
				<pie-chart></pie-chart>
			</div>
		</div>
	</div>
</template>

<script>
export default {
    name : 'report'
    
}
</script>

<style></style>
