<template>
  <div class="sidebar">
    <nav>
      <router-link to="/"><button :class="{selected: inicioSelected}" @click="selectOption('inicio')">Início</button></router-link>
      <router-link to="/adicionar_livros"><button :class="{selected: addLivrosSelected}" @click="selectOption('add-livros')">Adicionar Livros</button></router-link>
    </nav>
  </div>
</template>

<script>
export default {
  name: "app",
  data(){
    return {
      inicioSelected: true,
      addLivrosSelected: false

      
    }
  },
  methods: {
    selectOption(option){
      if(option == 'inicio'){
        this.inicioSelected = true;
        this.addLivrosSelected = false;
      }else if(option == 'add-livros'){
        this.inicioSelected = false;
        this.addLivrosSelected = true;

      }
    }
  },
  mounted(){
    if(this.$router.currentRoute.name == 'AddLivros'){
      this.inicioSelected = false;
      this.addLivrosSelected = true;
    }
  }
};
</script>

<style>
.sidebar {
  height: -webkit-calc(100vh - 100px);
  min-height: 500px;
  max-height: 700px;
  width: 250px;
  background: grey;
  float: left;
}
.sidebar button {
  display: block;
  padding: 20px;
  width: 100%;
  font-size: 14px
}
.selected {
  font-weight: 700;
  text-decoration: underline
}
</style>
