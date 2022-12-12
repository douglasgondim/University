import json
import unidecode
municipios = {}

with open('municipios_IBGE.json') as json_file:
    listaIBGE = json.load(json_file)

    for index, i in enumerate(listaIBGE):
        mesorregiao = i['microrregiao']['mesorregiao']
        nomeCidade = unidecode.unidecode(i['nome']).lower()
        municipios[nomeCidade] = { 'cidade': i['nome'], 'mesorregiao': mesorregiao['nome'], 'estado_sigla': mesorregiao['UF']['sigla'], 'estado_nome': mesorregiao['UF']['nome']  }
        
    municipios_JSON = json.dumps(municipios, indent = 3, ensure_ascii=False)
    print(type(municipios_JSON))
    json_file.close()

f = open('municipios.json', 'w')
f.write(municipios_JSON)
f.close()