<template>
	<div class="container">
		<br />
		<br />
		<div class="row">
			<div class="col-md-6 loginRight">
				<br />
				<br />
				<div>
					<h1 class="headingText">Hey User</h1>
					<p class="headingText">Let's Track your expenses</p>
				</div>
				<br />

				<form>
					<div class="mb-3 loginfield">
						<input
							type="text"
							class="form-control"
							id="spendTitle"
							placeholder="Title"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="text"
							class="form-control"
							id="category"
							placeholder="Enter category"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="number"
							class="form-control"
							id="amount"
							placeholder="Enter Amount"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="date"
							class="form-control"
							id="enterDate"
							placeholder="Enter the date"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="text"
							class="form-control"
							id="description"
							placeholder="Description(optional)"
						/>
					</div>
					<br />
					<router-link
						type="submit"
						class="btn btn-primary loginfield loginfieldButton"
						to=""
					>
						Add to expense
					</router-link>
				</form>
			</div>

			<!-- Table -->
			<div class="col-md-6">
				<div class="report">
					<router-link type="submit" class="btn btn-primary" to="/Report">
						Get Report
					</router-link>
				</div>
				<br />
				<br />
				<br />

				<table class="table table-dark">
					<thead>
						<tr>
							<th scope="col">Spend Title</th>
							<th scope="col">Category</th>
							<th scope="col">Amonunt</th>
							<th scope="col">Date</th>
							<th scope="col">Description</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<th scope="row">Book Purchase</th>
							<td>Book</td>
							<td>200</td>
							<td>12-07-2021</td>
							<td>No description</td>
						</tr>
						<tr>
							<th scope="row">Recharge for family</th>
							<td>Recharge</td>
							<td>450</td>
							<td>15-07-2021</td>
							<td>Done 3 recharges for family</td>
						</tr>
						<tr>
							<th scope="row">Grocery purcahse</th>
							<td>Grocery</td>
							<td>1000</td>
							<td>20-07-2021</td>
							<td>No description</td>
						</tr>
					</tbody>
				</table>
			</div>
		</div>
	</div>
</template>

<script>

// import Transactions from '../ExpenseService';

// export default {
// 	name:'Transaction',
// 	data() {
// 		return{
// 			transactions: [],
// 			newTransaction: {
// 				title :'',
// 				amount:'',
// 				description: ''
// 			},
// 		}
// 	},
// async created (){
	
// 		try {
// 			this.transactions =await ExpenseService.getTransactions();
// 		} catch (err) {
// 			console.log(error)
// 		}
// 	}
// };

export default{}
</script>

<style scooped></style>
