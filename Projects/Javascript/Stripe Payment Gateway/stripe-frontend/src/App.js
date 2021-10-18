import React, { useState } from "react";
import "./App.css";
import StripeCheckout from "react-stripe-checkout";
import Github from "./github.svg";

function App() {
  const [product, setProduct] = useState({
    name: "React Crash Course",
    price: 11.99,
    productBy: "Abhinn krishn",
  });
  const [isPaid, setIsPaid] = useState(false);

  const makePayment = (token) => {
    const body = {
      token,
      product,
    };
    const headers = {
      "Content-Type": "application/json",
    };

    return fetch(`http://localhost:8282/payment`, {
      method: "POST",
      headers,
      body: JSON.stringify(body),
    })
      .then((response) => {
        console.log("RESPONSE ", response);
        const { status } = response;
        console.log("STATUS ", status);
        setIsPaid(true);
      })
      .catch((error) => console.error(error));
  };

  return (
    <div className="App">
      <h1>Stripe Payment Gateway</h1>
      {/* PRODUCT CARD */}
      <div
        class="card"
        style={{ width: "300px", margin: "auto", marginBottom: "25px" }}
      >
        <div class="card-image waves-effect waves-block waves-light">
          <img
            class="activator"
            src="https://ik.imagekit.io/abhinnkriishn/07e300a1c3f095a2aec35d0c576002ab1927f9e7_89U8KzU44.webp?updatedAt=1633873696202"
            alt=""
            style={{ width: "300px" }}
          />
        </div>
        <div class="card-content">
          <span class="card-title activator grey-text text-darken-4">
            React Crash Course
          </span>
        </div>
      </div>
      {/* STRIPE PAYMENT BUTTON */}
      <StripeCheckout
        stripeKey="pk_test_51JijmCSGQxmIccxuUVK60U7w0i2V3wTftpxdwfBpesGpdH4JgljL86VqdzZQEq3bHSvnTffx6o7TienjAyg0zhxs00okie59Rq"
        token={makePayment}
        name="Buy React"
        amount={product.price * 100}
      >
        {isPaid ? (
          <></>
        ) : (
          <button className="btn-large blue">Buy ${product.price}</button>
        )}
      </StripeCheckout>
      {isPaid ? <div className="btn-large green">Purchased</div> : <></>}

      {/* footer */}
      <footer
        style={{
          padding: "3rem",
        }}
      >
        <h6>
          Made by:{" "}
          <a
            href="https://abhinnkrishn.me/"
            target="_blank"
            rel="noreferrer"
            className="green-text"
          >
            Abhinn Krishn
          </a>
          <a
            href="https://github.com/abhinnxo/"
            target="_blank"
            rel="noreferrer"
          >
            <img
              src={Github}
              width="25px"
              alt=""
              style={{
                marginLeft: "10px",
                transform: "translateY(7px)",
                cursor: "pointer",
              }}
            />
          </a>
        </h6>
      </footer>
    </div>
  );
}

export default App;
