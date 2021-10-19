var seiveOfEratosthenes = function (n) {
    //Eratosthenes algorithm to find all prims under n
    var array = [], upperlimit = Math.sqrt(n), output = [];

    //make an array from 2 to (n-1) elements
    for (var i = 0; i < n; i++) {
        array.push(true);
    }

    //removing all mutiples of primes starting from 2 and then consecutive primes
    for (var i = 2; i <= upperlimit; i++) {
        if (array[i]) {
            for (var j = i * i; j < n; j += i) {
                array[j] = false;
            }
        }
    }

    //All array[i] set to true if all are primes 
    for (var i = 2; i < n; i++) {
        if (array[i]) {
            output.push(i);
        }
    }

    return output;
}

//time complexity = O(nlogn)
//space complexity = O(√n)