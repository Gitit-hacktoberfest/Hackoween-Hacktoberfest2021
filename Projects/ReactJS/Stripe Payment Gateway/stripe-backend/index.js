const { v4: uuidv4 } = require("uuid");
const cors = require("cors");
const express = require("express");
const stripe = require("stripe")(
  "sk_test_51JijmCSGQxmIccxuwPhvoqVq8Yv07MywIS03DByYICRBoK3OM4LK9s7qnjqrUOPOwh3qJSPkRVdxU7MhBIUDL6Ow00224eJRYx"
);

const app = express();

// middlewares

app.use(express.json());
app.use(cors());

//  routes

app.get("/", (req, res) => {
  res.send("It is working...    ");
});

app.post("/payment", (req, res) => {
  const { product, token } = req.body;
  console.log("PRODUCR ", product);
  console.log("PRICE ", product.price);

  const idempontencyKey = uuidv4();

  return stripe.customers
    .create({
      email: token.email,
      source: token.id,
    })
    .then((customer) => {
      stripe.charges.create(
        {
          amount: product.price * 100,
          currency: "usd",
          custmer: customer.id,
          receipt_email: token.email,
          description: `Purchase of ${product.name}`,
          shipping: {
            name: token.card.name,
            address: {
              country: token.card.address_country,
            },
          },
        },
        { idempontencyKey }
      );
    })
    .then((result) => res.status(200).json(result))
    .catch((err) => console.error(err));
});

// listening

app.listen(8282, () => console.log("listening 8282"));
