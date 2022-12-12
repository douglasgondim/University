/* 
Equipe:

José Douglas Gondim Soares, Mat 416753
Thalita Pinheiro Paulo Vesco, Mat 415035
Joyce da Silva Simões, Mat 428478

*/

const predicados = [
    {
        professor: 'bonfim',
        disciplinas: [
            { nome: 'compiladores', semestre: 7, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'teoria-da-computacao', semestre: 7, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'linguagens-formais-e-automatos', semestre: 6, curso: ['cc'], qtd_aula_semana: 2 },
        ]
    },

    {
        professor: 'alexandre',
        disciplinas: [
            { nome: 'logica', semestre: 4, curso: ['cc', 'es'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'beatriz',
        disciplinas: [
            { nome: 'arquitetura-de-software', semestre: 6, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'introducao-a-engenharia-de-software', semestre: 1, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'qualidade-de-software', semestre: 6, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'projeto-de-pesquisa-cientifica-e-tecnologica', semestre: 6, curso: ['cces'], qtd_aula_semana: 1 },
        ]
    },

    {
        professor: 'daniel',
        disciplinas: [
            { nome: 'fundamentos-de-banco-de-dados', semestre: 4, curso: ['cc', 'es'], qtd_aula_semana: 2 },
            { nome: 'computacao-grafica', semestre: 5, curso: ['cc'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'eurinardo',
        disciplinas: [
            { nome: 'laboratorio-de-programacao', semestre: 2, curso: ['cc', 'es'], qtd_aula_semana: 2 },
            { nome: 'estrutura-de-dados-avancadas', semestre: 4, curso: ['cc'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'filipe',
        disciplinas: [
            { nome: 'desenvolvimento-de-software-para-web', semestre: 6, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'sistemas-distribuidos', semestre: 6, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'redes-de-computadores', semestre: 5, curso: ['cces'], qtd_aula_semana: 2 }

        ]
    },

    {
        professor: 'nauber',
        disciplinas: [
            { nome: 'linguagens-de-programacao', semestre: 3, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'processos-de-software', semestre: 4, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'manutencao-de-software', semestre: 6, curso: ['es'], qtd_aula_semana: 2 }

        ]
    },

    {
        professor: 'osvaldo',
        disciplinas: [
            { nome: 'introducao-a-processos-e-requisitos-de-software', semestre: 2, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'gerencia-de-projetos-de-software', semestre: 5, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'analise-e-projetos-de-sistemas', semestre: 4, curso: ['cces'], qtd_aula_semana: 2 }

        ]
    },

    {
        professor: 'josemeire',
        disciplinas: [
            { nome: 'empreendedorismo', semestre: 6, curso: ['cces'], qtd_aula_semana: 2 },
            { nome: 'etica-profissional', semestre: 1, curso: ['cc', 'es'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'marcio',
        disciplinas: [
            { nome: 'projeto-e-analise-de-algoritmos', semestre: 4, curso: ['cces'], qtd_aula_semana: 2 },
            { nome: 'fundamentos-de-programacao', semestre: 1, curso: ['cc', 'es'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'joao-victor',
        disciplinas: [
            { nome: 'programacao-orientada-a-objetos', semestre: 3, curso: ['cc', 'es'], qtd_aula_semana: 2 },
            { nome: 'verificacao-e-validacao', semestre: 6, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'projeto-detalhado-de-software', semestre: 5, curso: ['es'], qtd_aula_semana: 2 }

        ]
    },

    {
        professor: 'pablo',
        disciplinas: [
            { nome: 'algoritmos-em-grafos', semestre: 3, curso: ['cc', 'es'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'tatiane',
        disciplinas: [
            { nome: 'matematica-computacional', semestre: 6, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'estrutura-de-dados', semestre: 2, curso: ['cc', 'es'], qtd_aula_semana: 2 },
        ]
    },

    {
        professor: 'patricia',
        disciplinas: [
            { nome: 'requisitos-de-software', semestre: 3, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'engenharia-de-software', semestre: 4, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'interacao-humano-computador', semestre: 5, curso: ['cc', 'es'], qtd_aula_semana: 2 }

        ]
    },

    {
        professor: 'alex',
        disciplinas: [
            { nome: 'sistemas-operacionais', semestre: 5, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'inteligencia-artificial', semestre: 6, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'arquitetura-de-computadores', semestre: 2, curso: ['cc', 'es'], qtd_aula_semana: 2 }

        ]
    },

    {
        professor: 'gleyson',
        disciplinas: [
            { nome: 'matematica-basica', semestre: 1, curso: ['es'], qtd_aula_semana: 2 },
            { nome: 'calculo-diferencial-e-integral-I', semestre: 2, curso: ['cc'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'gastao',
        disciplinas: [
            { nome: 'matematica-basica', semestre: 1, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'algebra-linear', semestre: 3, curso: ['cc'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'rosineide',
        disciplinas: [
            { nome: 'probabilidade-e-estatistica', semestre: 3, curso: ['cc'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'anderson-feitoza',
        disciplinas: [
            { nome: 'matematica-discreta', semestre: 2, curso: ['cc', 'es'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'nilde',
        disciplinas: [
            { nome: 'probabilidade-e-estatistica', semestre: 3, curso: ['es'], qtd_aula_semana: 2 },

        ]
    },

    {
        professor: 'anderson-magno',
        disciplinas: [
            { nome: 'pre-calculo', semestre: 1, curso: ['cc'], qtd_aula_semana: 1 },
        ]
    },
    {
        professor: 'rafael-ivo',
        disciplinas: [
            { nome: 'introducao-a-ciencia-da-computacao', semestre: 1, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'linguagens-de-programacao', semestre: 3, curso: ['cc'], qtd_aula_semana: 2 },
            { nome: 'sistemas-operacionais', semestre: 5, curso: ['cc'], qtd_aula_semana: 2 }

        ]
    }


]



const dias_da_semana = ['seg', 'ter', 'qua', 'qui', 'sex']

const horarios = ['H1', 'H2', 'H3', 'H4']

let big_string = '';
let big_string2 = '';
let pode_dar_quebra_de_linha = false;
let pode_dar_quebra_de_linha2 = false;
let predicado_string;
let predicado_string2;

imprimePredicados = (predicados) => {
    predicados.forEach(objeto => {
        objeto.disciplinas.forEach(disciplina => {
            disciplina.curso.forEach(curso => {
                dias_da_semana.forEach(dia => {
                    horarios.forEach(horario => {

                        predicado_string = objeto.professor + '_' + disciplina.nome + '_' + curso + '_' + disciplina.semestre + '_' + dia + '_' + horario + '_' + disciplina.qtd_aula_semana;

                        predicados.forEach(objeto2 => {
                            objeto2.disciplinas.forEach(disciplina2 => {
                                disciplina2.curso.forEach(curso2 => {
                                    dias_da_semana.forEach(dia2 => {
                                        horarios.forEach(horario2 => {
                                            predicado_string2 = objeto2.professor + '_' + disciplina2.nome + '_' + curso2 + '_' + disciplina2.semestre + '_' + dia2 + '_' + horario2 + '_' + disciplina2.qtd_aula_semana;

                                            // regra que cada disciplina é ofertada
                                            regraCadaDiscEhOfertada(disciplina, disciplina2, curso, curso2, dia, horario);

                                            // regra que cada disciplina ocorre apenas uma ou duas vezes na semana.
                                            regraDiscOcorreUmaOuDuas(objeto, objeto2, disciplina, disciplina2, dia, dia2, horario, horario2, curso, curso2);

                                            // regra professor só pode dar aula na Segunda-feira ou Sexta-feira, exclusivamente.
                                            regraSegOuSexExlusivo(objeto, objeto2, dia, dia2);

                                            // regra cada professor tem disciplina ou na Segunda-feira ou na Sexta-feira
                                            regraCadaProfTemDiscSegOuSex(objeto, objeto2, disciplina, curso, curso2, dia, dia2, horario);

                                            // regra disciplinas do mesmo semestre não podem colidir.
                                            regraDiscMesmoSemestreNaoColide(disciplina, disciplina2, curso, curso2, dia, dia2, horario, horario2);


                                            // regra professores nao podem colidir horario entre suas disciplinas
                                            regraProfNaoColideHorarios(objeto, objeto2, dia, dia2, horario, horario2);


                                            // regra disciplinas para cces não podem ter horarios conflitantes com cadeiras do mesmo semestre nem de cc nem de es.
                                            regraDiscCCESNaoColidem(disciplina, disciplina2, curso, curso2, dia, dia2, horario, horario2);


                                        })
                                    })
                                })
                            })
                        })


                    })



                })




            })
        })


    })


}

regraSegOuSexExlusivo = (objeto, objeto2, dia, dia2) => {
    if (objeto.professor == objeto2.professor) {
        if (dia == 'seg') {
            if (dia2 == 'sex') {
                let professor_seg_implica_nao_sexta = '-' + predicado_string + ' ' + '-' + predicado_string2;
                let professor_sex_implica_nao_segunda = '-' + predicado_string2 + ' ' + '-' + predicado_string;

                fs.appendFileSync('predicados.txt', professor_seg_implica_nao_sexta + '\n', function (err) {
                    if (err) throw err;

                });
                fs.appendFileSync('predicados.txt', professor_sex_implica_nao_segunda + '\n', function (err) {
                    if (err) throw err;

                });

            }

        }

    }

}

regraCadaDiscEhOfertada = (disciplina, disciplina2, curso, curso2, dia, horario) => {
    if (disciplina == disciplina2 && dia == dias_da_semana[0] && horario == horarios[0] && curso == curso2) {
        big_string += predicado_string2 + ' ';
        pode_dar_quebra_de_linha = true;

    } else if (pode_dar_quebra_de_linha) {
        fs.appendFileSync('predicados.txt', big_string + '\n\n\n', function (err) {
            if (err) throw err;

        });
        big_string = '';
        pode_dar_quebra_de_linha = false;

    }

}

regraProfNaoColideHorarios = (objeto, objeto2, dia, dia2, horario, horario2) => {
    if (objeto.professor == objeto2.professor && dia == dia2 && horario == horario2 && predicado_string != predicado_string2) {
        let professor_nao_colide = '-' + predicado_string + ' ' + '-' + predicado_string2;

        fs.appendFileSync('predicados.txt', professor_nao_colide + '\n', function (err) {
            if (err) throw err;

        });

    }

}

regraDiscMesmoSemestreNaoColide = (disciplina, disciplina2, curso, curso2, dia, dia2, horario, horario2) => {
    if (disciplina.semestre == disciplina2.semestre && curso == curso2 && horario == horario2 && dia == dia2 && disciplina != disciplina2) {
        let disciplina_semestre_nao_colide = '-' + predicado_string + ' ' + '-' + predicado_string2;
        fs.appendFileSync('predicados.txt', disciplina_semestre_nao_colide + '\n', function (err) {
            if (err) throw err;

        });

    }
}

regraDiscCCESNaoColidem = (disciplina, disciplina2, curso, curso2, dia, dia2, horario, horario2) => {
    if (curso == 'cces' && disciplina.semestre == disciplina2.semestre && dia == dia2 && horario == horario2 && curso != curso2) {
        let disciplina_cces_nao_colide = '-' + predicado_string + ' ' + '-' + predicado_string2;
        let disciplina_cces_nao_colide2 = '-' + predicado_string2 + ' ' + '-' + predicado_string;

        fs.appendFileSync('predicados.txt', disciplina_cces_nao_colide + '\n', function (err) {
            if (err) throw err;

        });
        fs.appendFileSync('predicados.txt', disciplina_cces_nao_colide2 + '\n', function (err) {
            if (err) throw err;

        });

    }

}

regraCadaProfTemDiscSegOuSex = (objeto, objeto2, disciplina, curso, curso2, dia, dia2, horario) => {
    if (objeto.professor == objeto2.professor && disciplina == objeto.disciplinas[0] && dia == dias_da_semana[0] && horario == horarios[0] && curso == curso2) {
        if (dia2 == 'seg' || dia2 == 'sex') {
            big_string2 += predicado_string2 + ' ';
            pode_dar_quebra_de_linha2 = true;
        }

    } else if (pode_dar_quebra_de_linha2) {
        fs.appendFileSync('predicados.txt', big_string2 + '\n\n\n', function (err) {
            if (err) throw err;

        });
        big_string2 = '';
        pode_dar_quebra_de_linha2 = false;

    }

}

regraDiscOcorreUmaOuDuas = (objeto, objeto2, disciplina, disciplina2, dia, dia2, horario, horario2, curso, curso2) => {
    if (disciplina == disciplina2 && objeto.professor == objeto2.professor && (horario != horario2 || dia != dia2) && curso == curso2) {
        if (disciplina.qtd_aula_semana == 1) {
            let ocorre_uma_vez = '-' + predicado_string + ' ' + '-' + predicado_string2;
            fs.appendFileSync('predicados.txt', ocorre_uma_vez + '\n', function (err) {
                if (err) throw err;

            });

        }

        let ocorre_duas_vezes;
        if (disciplina.qtd_aula_semana == 2) {
            if (dia == 'seg') {
                if (dia2 != 'qua' || horario != horario2) {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + '-' + predicado_string2
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });

                } else {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });
                }
            } else if (dia == 'ter') {
                if (dia2 != 'qui' || horario != horario2) {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + '-' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });
                } else {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });

                }
            } else if (dia == 'qua') {
                if ((dia2 != 'sex' && dia2 != 'seg') || horario != horario2) {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + '-' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });

                } else if (dia2 == 'seg' && horario == horario2 && curso == curso2) {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });
                }
            } else if (dia == 'qui') {
                if (dia2 != 'ter' || horario != horario2) {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + '-' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });


                } else {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });
                }
            } else if (dia == 'sex') {
                if (dia2 != 'qua' || horario != horario2) {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + '-' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });


                } else {
                    ocorre_duas_vezes = '-' + predicado_string + ' ' + predicado_string2;
                    fs.appendFileSync('predicados.txt', ocorre_duas_vezes + '\n', function (err) {
                        if (err) throw err;

                    });
                }

            }
        }
    }


}

var fs = require('fs');

fs.unlink('predicados.txt', function (err) {
    if (err) throw err;
});

var fs = require('fs');
imprimePredicados(predicados);

