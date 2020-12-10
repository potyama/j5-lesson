import MeCab
tagger = MeCab.Tagger()

result = tagger.parse("かなたは大学生だよ。")
print(result)