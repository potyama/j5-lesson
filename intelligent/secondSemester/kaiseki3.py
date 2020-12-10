import MeCab

tagger = MeCab.Tagger("-d /usr/lib/mecab/dic/mecab-ipadic-neologd/")
S = input("文を入力:")
tagger.parse("")
node = tagger.parseToNode(S)
old_node = tagger.parseToNode(S)

old_result = []
old_part_of_speech = []
result = []
part_of_speech = []


while old_node is not None:
    if old_node.feature.split(",")[6] != '*':
        old_result.append(old_node.feature.split(",")[6])
        old_part_of_speech.append(old_node.feature.split(",")[0])

    old_node = old_node.next

print("弾く前：")
print(old_result)
print(old_part_of_speech)

while node is not None:
    hinshi = node.feature.split(",")[0]
    if  hinshi in ["名詞"]:
        result.append(node.surface)
        part_of_speech.append(node.feature.split(",")[0])

    elif hinshi in ["動詞", "形容詞"]:
        result.append(node.feature.split(",")[6])

    node = node.next

print("弾いた後:")
print(result)
print(part_of_speech)