<template>

  <div class="container-view">
    <div class="search">
      <input
        type="text"
        placeholder="Pesquisar por título..."
        v-model.lazy="search.titulo"
      >
      <input
        type="text"
        placeholder="Pesquisar por autor..."
        v-model.lazy="search.autor"
      >

      <button @click="searchBook(search)">Buscar</button>
      <button
        id="reset-button"
        @click="resetSearch()"
      >Resetar</button>
    </div>

    <div
      v-for="(livro, index) in livros"
      v-bind:key="livro.id"
      :class="{livro, 'fair-color' : index % 2 == 1 }"
    >
      <div class="titulo-livro">
        <p><span class="bold"> {{livro.autor}}, {{livro.titulo}} - {{livro.ano_publicacao}}</span></p>
      </div>
      <div class="botoes-livro">
        <router-link :to="{name:'Capitulos', params: {id: livro._id }}"><button id="chapters-button">Ver Capítulos</button></router-link>
        <button @click="editBook(livro)"><img
            src="../assets/edit.png"
            alt="Edit Button"
          ></button>
        <button @click="deleteBook(livro._id)"><img
            src="../assets/delete.png"
            alt="Edit Button"
          ></button>
      </div>
    </div>

    <template>

      <b-modal id="edit-modal">
        <template v-slot:modal-header="{ close }">
          <h5>Editar Livro</h5>
          <b-button
            size="sm"
            variant="bg-white"
            @click="close()"
          >
            <img
              id="close-button"
              src="../assets/close.png"
              alt="close"
            >
          </b-button>

        </template>

        <template v-slot:default="{ hide }">
          <div class="form-content">
            <form class="form-book">
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

            </form>
          </div>
        </template>

        <template v-slot:modal-footer="{ ok, cancel}">

          <b-button
            size="sm"
            variant="danger"
            @click="cancel()"
          >
            Cancelar
          </b-button>
          <b-button
            size="sm"
            variant="success"
            @click="updateBookRequest()"
          >
            Editar
          </b-button>

        </template>
      </b-modal>
    </template>

    <b-modal id="edit-modal2" size="lg" title="Editar livro">

      
    
    </b-modal>
  </div>

</template>

<script>
import axios from "axios";

export default {
  name: "app",
  data() {
    return {
      livros: [],
      livro: {
        id: "",
        titulo: "",
        autor: "",
        ano_publicacao: 0,
        capitulos: []
      },
      capitulo: {
        id: "",
        titulo: "",
        conteudo: ""
      },
      search: {
        titulo: "",
        autor: ""
      },
      test: "la"
    };
  },
  methods: {
    fetchAllBooks() {
      axios
        .get("http://localhost:8080/api/books")
        .then(response => {
          this.livros = response.data;
        })
        .catch(() => {
          this.$bvModal.msgBoxOk("Erro ao buscar livros");
        });
    },
    deleteBook(bookID) {
      this.$bvModal
        .msgBoxConfirm("Tem certeza que deseja apagar o livro?", {
          size: "md",
          buttonSize: "sm",
          okVariant: "danger",
          okTitle: "Sim",
          cancelTitle: "Cancelar",
          footerClass: "p-2",
          hideHeaderClose: false,
          centered: true
        })
        .then(value => {
          if (value) {
            axios
              .delete("http://localhost:8080/api/books/" + bookID)
              .then(() => {
                this.fetchAllBooks();
              });
          }
        })
        .catch(() => {
          this.$bvModal.msgBoxOk("Erro ao apagar livro!");
        });
    },
    editBook(book) {
      this.livro.autor = book.autor;
      this.livro.titulo = book.titulo;
      this.livro.ano_publicacao = book.ano_publicacao;
      this.livro.id = book._id;

      this.$bvModal.show("edit-modal");
    },
    updateBookRequest() {
      axios
        .put("http://localhost:8080/api/books/" + this.livro.id, this.livro, {
          headers: {
            "Content-type": "application/json"
          }
        })
        .then(() => {
          this.$bvModal.hide("edit-modal");
          this.fetchAllBooks();
          this.$bvModal.msgBoxOk("Livro editado com sucesso!");
        })
        .catch(() => {
          this.$bvModal.msgBoxOk("Erro ao editar livro!");
        });
    },
    searchBook(search2) {
      axios
        .get(
          "http://localhost:8080/api/books?" +
            "titulo=" +
            search2.titulo +
            "&autor=" +
            search2.autor
        )
        .then(response => {
          this.livros = response.data;
          if (response.data.length == 0) {
            this.fetchAllBooks();
            this.$bvModal.msgBoxOk("Nenhum livro encontrado com os filtros!");
          }
        });
    },
    resetSearch() {
      this.search.titulo = "";
      this.search.autor = "";
      this.fetchAllBooks();
    }
  },

  mounted() {
    this.fetchAllBooks();
  }
};
</script>

<style>
.livro {
  background: rgb(210, 210, 210);
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 10px;
  margin: 1px 0;
  border-bottom: 1px solid grey;
  border-top: 1px solid grey;
}
.fair-color {
  background: rgb(235, 235, 235);
}
.livro img {
  height: 25px;
}
.titulo-livro {
  width: 100%;
  padding: 0 12px;
}
.botoes-livro {
  display: flex;
  justify-content: flex-end;
}
.botoes-livro button {
  margin: 0 4px;
  border: 1px solid grey;
}
.search {
  padding: 8px;
  display: flex;
  justify-content: center;
}
.search input {
  width: 100%;
  margin: 0 10px 0 0;
  padding: 4px 8px;
  border-radius: 10px;
}
#chapters-button {
  font-size: 14px;
}
.container-view {
  font-size: 14px;
}
#close-button {
  object-fit: contain;
  height: 15px;
}
.form-content {
  display: flex;
  justify-content: center;
}
#reset-button {
  margin-left: 8px;
}

</style>
