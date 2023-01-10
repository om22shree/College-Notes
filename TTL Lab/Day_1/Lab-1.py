#!/usr/bin/env python
# coding: utf-8

# # Print statements

# In[30]:


print("My name is Om")
print("Hello World!")


# # Variable declaration

# In[32]:


miles = 1000
name = "Om"
print(miles, "+", name)
while miles <= 1005 :
    print(miles)
    miles += 1
    
a, b, c = 15, 7.7, "Shree"
print(a, b, c)


# # Typecasting

# In[33]:


print(type(a))
print(type(b))
print(type(c))
print(56+100, 56*100, 56/100, 56-100)
fl = 100
print(float(fl))
print(str(fl))
print(type(str(fl)))


# # Lists

# In[74]:


ls = ["om", 77, "shree", 56, 100.24, True]
print(ls)
print(ls[0], ls[2])
print(ls[1:3])
print(ls[1:])
print(ls * 2)
print(type(ls))


# # List operations

# In[75]:


print(len(ls))
print("om" in ls, 23 in ls)
print(ls)
ls.insert(2, "Gautam")
print(len(ls))
print(ls)


# Try for urself: max, min, compare, append, count, extend, remove, reverse, sort, 

# In[102]:


ls2 = [100, 200, 300, 77, 32, 420]
print(max(ls2))
print(min(ls2))
ls2.sort()
print(ls2)
print(ls == ls2)
ls2.reverse()
print(ls2)
print(ls2.count(77))
ls2.remove(32)
print(ls2)
ls2.append(ls)
print(ls2)
ls2.extend(ls)
print(ls2)
ls2.extend("Om")
print(ls2)


# # Dictionaries

# In[113]:


student = {
    "name" : "Om",
    "roll" : 77,
    "cgpa" : 9.3
}
print(student)
print(student["roll"])


# # Nested dictionary

# In[117]:


employ = {
    "Om" : {
        "name" : "Om",
        "roll" : 77,
        "department" : "management"
    },
    
    "Gautam" : {
        "name" : "Gautam",
        "roll" : 122,
        "department" : "development"
    }
}
print(employ)
print(employ["Om"])


# In[ ]:




