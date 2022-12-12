<template>

  <div class="container-view">
    <div class="title-area">
      <h4 id="main-title">{{livro.autor}}, {{livro.titulo}} - {{livro.ano_publicacao}}</h4>

    </div>
    
    <div class="add-chapter-button-holder">
      <button
        @click="openAddChapterForm()"
        id="add-chapter-button"
      >Adicionar Capítulo</button>
    </div>

    <div
      v-for="(capitulo, index) in livro.capitulos"
      v-bind:key="capitulo.id"
      :class="{livro, 'fair-color': index % 2 == 1}"
    >
      <div class="titulo-livro">
        <p><span class="bold">Capítulo {{index + 1}}:</span> {{capitulo.titulo}}</p>
      </div>
      <div class="botoes-livro">
        <button @click="viewChapter(capitulo.id)" id="view-button">Visualizar</button>
        <button @click="openEditModal(capitulo.id)"><img
            src="../assets/edit.png"
            alt="Edit Button"
          ></button>
        <button @click="deleteChapter(capitulo.id)"><img
            src="../assets/delete.png"
            alt="Edit Button"
          ></button>
      </div>
    </div>
    <b-modal
      size="lg"
      id="add-chapter-modal"
    >
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
              v-model.lazy="capitulo.titulo"
            >
              <label for="conteudo">Conteúdo</label>
             <b-form-textarea
            id="conteudo"
            placeholder="Conteúdo"
            rows="8"
            v-model.lazy="capitulo.conteudo"
          ></b-form-textarea>
        
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
          @click="addChapter(capitulo)"
        >
          Adicionar
        </b-button>

      </template>
    </b-modal>
<!-- --------------------------------------- -->
    <b-modal
      size="lg"
      id="edit-chapter-modal"
    >
      <template v-slot:modal-header="{ close }">

        <h5>Editar Capítulo</h5>
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
              v-model.lazy="capitulo.titulo"
            >
              <label for="conteudo">Conteúdo</label>
             <b-form-textarea
            id="conteudo"
            placeholder="Conteúdo"
            rows="8"
            v-model.lazy="capitulo.conteudo"
          ></b-form-textarea>
          
       
            

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
          @click="editChapter(capitulo)"
        >
          Editar
        </b-button>

      </template>
    </b-modal>

<!-- --------------------------------------- -->
 

  <b-modal id="view-chapter" size="lg" ok-only="" ok-title="Voltar" scrollable :title="capitulo.titulo">
    <p class="my-4">
      {{capitulo.conteudo}}
    </p>
  </b-modal>

  </div>

</template>

<script>

import axios from "axios";

export default {
  name: "app",
  components: {},
  props: ["id"],
  data() {
    return {
      livro: {
        titulo: "",
        autor: "",
        ano_publicacao: null,
        capitulos: []
      },
      capitulo: {
        id: "",
        titulo: "",
        conteudo: ""
      }
    };
  },
  methods: {
    getBookById(bookID) {
      axios.get("http://localhost:8080/api/books/" + bookID).
      then(response => {
        this.livro.id = response.data._id;
        this.livro.titulo = response.data.titulo;
        this.livro.autor = response.data.autor;
        this.livro.ano_publicacao = response.data.ano_publicacao;
        this.livro.capitulos = [];

        response.data.capitulos.forEach(capitulo => {
          this.capitulo.id = capitulo._id;
          this.capitulo.titulo = capitulo.nome;
          this.livro.capitulos.push({...this.capitulo});
        });
        this.$bvModal.hide("add-chapter-modal");

           
      });
    },
    viewChapter(chapterID){
      this.fetchChapter(chapterID);
      this.$bvModal.show("view-chapter");
    },
    openAddChapterForm() {
      this.cleanChapters();
      this.$bvModal.show("add-chapter-modal");
    },
    cleanChapters() {
      this.capitulo.id = "";
      this.capitulo.titulo = "";
      this.capitulo.conteudo = "";
    },
    addChapter(chapter) {
      const chapterObject = {
        nome: chapter.titulo,
        conteudo: chapter.conteudo
      };
      axios
        .post(
          "http://localhost:8080/api/books/" + this.livro.id + "/chapters",
          chapterObject,
          {
            headers: {
              "Content-type": "application/json"
            }
          }
        )
        .then(() => {
          this.getBookById(this.livro.id);
        })
        .catch(() => {
          this.$bvModal.msgBoxOk("Erro ao adicionar capítulo!");
        });
    },
    deleteChapter(chapterID){
      this.$bvModal.msgBoxConfirm("Tem certeza que deseja apagar o capítulo?", {
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
              .delete("http://localhost:8080/api/books/" + this.livro.id + '/chapters/' + chapterID)
              .then(() => {
                this.getBookById(this.livro.id);
              });
          }
        })
        .catch(() => {
       
          this.$bvModal.msgBoxOk('Erro ao apagar capítulo!');
        });
    },
    openEditModal(capituloID){
      this.fetchChapter(capituloID);
      this.$bvModal.show("edit-chapter-modal");

    },
    fetchChapter(chapterID){
   
      axios.get("http://localhost:8080/api/books/" + this.livro.id + '/chapters/' + chapterID).
      then((response) => {
        this.capitulo.id = response.data._id;
        this.capitulo.titulo = response.data.nome;
        this.capitulo.conteudo = response.data.conteudo;
        return true;
      })
      .catch(() => {
       this.$bvModal.msgBoxOk('Erro ao buscar capítulo!')
      });
    },
    editChapter(capitulo){

      const chapterObject = {
        nome: capitulo.titulo,
        conteudo: capitulo.conteudo

      }
       axios
        .put("http://localhost:8080/api/books/" + this.livro.id + '/chapters/' + capitulo.id, chapterObject, {
          headers: {
            "Content-type": "application/json"
          }
        })
        .then(() => {
          this.$bvModal.hide("edit-chapter-modal");
          this.getBookById(this.livro.id);
          this.$bvModal.msgBoxOk("Capítulo editado com sucesso!");
        })
        .catch(() => {
          this.$bvModal.msgBoxOk("Erro ao editar capítulo!");
        });

    }
  },
  mounted() {
    this.getBookById(this.$route.params.id);
  }
};
</script>

<style>
.display-view {
  display: flex;
  flex-direction: column;
}
.form-book {
  display: flex;
  flex-direction: column;
  width: 80%;
}
.form-book label {
  margin-bottom: 4px;
}
.form-book input {
  margin-bottom: 12px;
  
  padding: 6px;
  border-radius: 4px;
}
.display-area {
  display: flex;
  align-items: center;
  flex-direction: column;

}
.submit-button {
  width: 60px;
  align-self: flex-end;
  /* padding: 4px; */
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
  margin-bottom: 0px;
}
#chapters-button {
  height: 100%;
}
.bold {
  font-weight: 700;
}
#add-chapter-button {
  padding: 8px;
  background: rgb(158, 255, 158);
  width: 170px;
}
.add-chapter-button-holder {
  display: flex;
  flex-direction: column;
  align-items: flex-end;
  padding: 12px;
}
.form-content {
  display: flex;
  justify-content: center;
}
.view-button {
  height: 100%;
}
.my-4 {
  line-height: 22px
}
</style>
