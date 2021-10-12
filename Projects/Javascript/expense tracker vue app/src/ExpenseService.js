// import axios from 'axios';
// console.log(err);

// const url = 'http://localhost:5000/api/v1/transactions/';

// class Transactions{
//     // Get Transactions
//     static getTransactions(){
//         return new Promise(async(resolve, reject) =>{
//             try{
//                 const res = await axios.get(url);
//                 const data = res.data;
//                 resolve(
//                     data.map(transaction => ({
//                         ...transaction,
//                         createdAt: new Date(transaction.createdAt)
//                     }))
//                 );
//             } catch(err) {
//                 reject(err);
//             }
//         })
    
//     }
//     // Add Transactions

//     static addTransactions(transactions){
//         return axios.transactions(url,{
//             "title" : transactions.title,
//             "amount" : transactions.amount,
//             "description": transactions.spendDescription,
            
//         })
//     }

//     // Delete Transactions

//     static deleteTransactions(id) {
//         return axios.delete(`${url}${id}`);
//     }
// }

// export default Transactions;