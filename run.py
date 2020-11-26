import sqlite3

'''Load the test data'''
def load_test(path):
	test_df = sqlite3.connect(path)
	return test_df



test_df = load_test("test/test-000010.db")
print("The test data is loaded successfully as test_df.")
