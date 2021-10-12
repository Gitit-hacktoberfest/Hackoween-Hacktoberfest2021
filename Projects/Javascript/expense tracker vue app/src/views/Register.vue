<template>
	<div class="container">
		<br />
		<br />
		<div class="row">
			<div class="col-md-6">
				<img
					class="worker"
					src="../../public/img/construction-worker-with-coin.png"
					alt="worker"
				/>
			</div>
			<div class="col-md-6 loginRight">
				<br />
				<br />
				<div>
					<h1 class="headingText">Start your e<b>X</b>pense account</h1>
					<p class="headingText">Keep track of your expenses</p>
				</div>
				<br />

				<form>
					<div class="mb-3 loginfield">
						<input
							type="text"
							class="form-control"
							id="fullName"
							placeholder="Full Name"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="email"
							class="form-control"
							id="email"
							aria-describedby="emailHelp"
							placeholder="Enter email"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="password"
							class="form-control"
							id="password"
							placeholder="Password"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="password"
							class="form-control"
							id="reenterpassword"
							placeholder="Re-enter password"
						/>
					</div>
					<br />
					<router-link
						type="submit"
						class="btn btn-primary loginfield loginfieldButton"
						to="/expense"
					>
						Sign Up
					</router-link>
				</form>
			</div>
		</div>
	</div>
</template>

<script>
export default {};
</script>

<style scoped></style>
