import MeCab
tagger = MeCab.Tagger("-d /usr/lib/mecab/dic/mecab-ipadic-neologd/")
tagger.parse("")
node = tagger.parseToNode("かなたは大学生だよ。")
result = []

while node is not None:
    hinshi = node.feature.split(",")[0]
    if  hinshi in ["名詞"]:
        result.append(node.surface)
    elif hinshi in ["動詞", "形容詞"]:
        result.append(node.feature.split(",")[6])
    node = node.next

print(result)