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
					<h1 class="headingText">Sign in to e<b>X</b>pense</h1>
					<p class="headingText">Keep track of your expenses</p>
				</div>
				<br />

				<form>
					<div class="mb-3 loginfield">
						<input
							type="email"
							class="form-control"
							id="exampleInputEmail1"
							aria-describedby="emailHelp"
							placeholder="Enter email"
						/>
					</div>
					<div class="mb-3 loginfield">
						<input
							type="password"
							class="form-control"
							id="exampleInputPassword1"
							placeholder="Enter password"
						/>
					</div>
					<div>
						<router-link
							type="submit"
							class="btn btn-primary loginfield loginfieldButton"
							to="/expense"
						>
							Login
						</router-link>
					</div>
				</form>
			</div>
		</div>
	</div>
</template>

<script>
export default {};
</script>

<style scoped></style>
