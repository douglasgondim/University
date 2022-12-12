<template>

  <div class="container-view">
    <div class="display-view">
      <div class="title-area">
        <h4 id="main-title">Adicionar Livro</h4>
      </div>
      <form class="form-add-book">
        <label for="title">Título</label>
        <input
          id="title"
          name="title"
          type="text"
          placeholder="Título"
          v-model.lazy="livro.titulo"
        >
        <label for="author">Autor</label>
        <input
          id="author"
          name="author"
          type="text"
          placeholder="Autor"
          v-model.lazy="livro.autor"
        >
        <label for="release_year">Ano de Publicação</label>
        <input
          id="release_year"
          name="release_year"
          type="number"
          placeholder="Ano Publicação"
          v-model.lazy.number="livro.ano_publicacao"
        >
        <button
          type="button"
          class="submit-button"
          @click="sendBook()"
        >Enviar</button>
      </form>
    </div>
  </div>

</template>

<script>
import axios from "axios";

export default {
  name: "app",
  components: {},
  data() {
    return {
      livro: {
        titulo: "",
        autor: "",
        ano_publicacao: null,
        capitulos: []
      },
      capitulo: {
        titulo: "",
        conteudo: ""
      }
    };
  },
  methods: {
    sendBook() {
      axios
        .post("http://localhost:8080/api/books", this.livro, {
          headers: {
            "Content-type": "application/json"
          }
        })
        .then(() => {
          this.clear();
          this.$bvModal.msgBoxOk('Livro adicionado com sucesso!')
        }).
        catch(() => {
          this.$bvModal.msgBoxOk('Erro ao adicionar livro!')
        });
    },
    clear() {
      this.livro.titulo = "";
      this.livro.autor = "";
      this.livro.ano_publicacao = null;
    }
  },
  mounted() {}
};
</script>

<style>
.display-view {
  display: flex;
  flex-direction: column;
  align-items: center;
}
.form-add-book {
  display: flex;
  flex-direction: column;
  width: 300px;
  margin-top: 30px;
}
.form-add-book input {
  margin-bottom: 12px;
  padding: 6px;
  border-radius: 4px;
}
.form-add-book label {
  margin-bottom: 4px
}
.display-area {
  display: flex;
  align-items: center;
  flex-direction: column;
}

.submit-button {
  width: 60px;
  align-self: flex-end;
  width: 100px;
  height: 30px;
}
.title-area {
  background: rgb(243, 251, 255);
  width: 100%;
  height: 50px;
  display: flex;
  justify-content: center;
  align-items: center;
  margin-bottom: 60px;
}
</style>
