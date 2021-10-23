
=begin
    Program to check whether an integer or a string is Palindrome or not
=end


def is_palindrome(x)
    str1 = x.to_s           #converion to String
    str2 = str1.reverse     #Reverse of the string
    if str1 == str2
        return true
    else
        return false
    end
end
num = 121
str = "MADAM"
strCheck = "MADAMS"
puts "Integer #{num} is Palindrome? #{is_palindrome(num)}"
puts "String #{str} is Palindrome? #{is_palindrome(str)}"
puts "String #{strCheck} is Palindrome? #{is_palindrome(strCheck)}"