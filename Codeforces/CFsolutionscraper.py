from bs4 import BeautifulSoup
import requests
import os

# user handle
handle = input('Enter Codeforces handle -> ')
startPage = 1
# no. of pages 
endPage = 43
i = 1
for i in range(endPage):
	submissionPageUrl = 'http://codeforces.com/submissions/'+handle+'/page/' + str(i)
	response = requests.get(submissionPageUrl)
	soup = BeautifulSoup(response.content, 'html.parser')
	rows = soup.find_all('tr')
	solutions = []
	# iterating through all rows of the page for finding accepted solutions
	for row in rows:
		try:
			status = row.find(class_='verdict-accepted').get_text().strip() 
			if status != 'Accepted':
				continue
			solutions.append(row.find(class_='view-source')['href'])
		except Exception as e:
			print(e)

	for solution in solutions:
		solutionPageUrl = 'http://codeforces.com'+solution
		response = requests.get(solutionPageUrl)
		soup = BeautifulSoup(response.content, 'html.parser')
		fileName = soup.findAll('a')[27].get_text().strip()+".cpp" 
		try:        
			f= open(fileName ,"w+")
			f.write(soup.find(class_='prettyprint lang-cpp program-source').get_text().strip())
		except Exception as e:
			print(e)