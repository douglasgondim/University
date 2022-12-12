<template>
  <div class="main-container">
    <Header />
    <Sidebar />
    
   

    <div class="display-area">
        <router-view/>
    </div>
  </div>

</template>

<script>

import Header from "../components/Header.vue";
import Sidebar from "../components/Sidebar.vue";

export default {
  name: "app",
  components: {
    Header,
    Sidebar
  },
  data() {
    return {
      livros: [],
      livro : {
          id: '',
          titulo: '',
          autor: '',
          anoPublicacao: 0,
          capitulos: []
      },
      capitulo: {
          id: '',
          titulo: '',
          conteudo: ''

      }
    };
  },
};
</script>

<style>

.main-container {
    background-color: rgb(213, 224, 253);
    height: 100vh;
    min-height: 500px;
    max-height: 800px;
    width: 1040px;
    margin: auto;

}

.display-area {
    overflow: scroll;
    height: -webkit-calc(100vh - 100px);
    min-height: 500px;
    max-height: 700px;
}

</style>
