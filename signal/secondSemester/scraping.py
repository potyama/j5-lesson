import csv
import urllib.request

from bs4 import BeautifulSoup


url = "https://info.finance.yahoo.co.jp/history/?code=998407.O&sy=2020&sm=9&sd=1&ey=2020&em=9&ed=30&tm=d"
html = urllib.request.urlopen(url)
soup = BeautifulSoup(html, 'html.parser')
table = soup.find_all("table")

for tab in table:
    table_className = tab.get("class")
    if table_className[0] == "boardFin":
        with open("closing_price.csv", "w", encoding = 'utf-8') as file:
            writer = csv.writer(file)
            rows = tab.find_all("tr")
            for row in rows:
                csvRow = []
                for cell in row.findAll(['td', 'th']):
                    csvRow.append(cell.get_text())
                writer.writerow(csvRow)
        break
