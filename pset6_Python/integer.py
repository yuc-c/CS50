# n = input("Input: ")
# if n.isnumeric(): # 檢查是否全數字
#     print("Integer.")
# else:
#     print("Not integer.")

try:
    n = int(input("Input: "))
except ValueError: # 當try執行錯誤 則執行這段
    print("Not integer.")
else:
    print("Integer.")
