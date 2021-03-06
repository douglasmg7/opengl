use gl;
use sdl2;

fn main() {
    let sdl = sdl2::init().unwrap();
    // Create a window.
    let video_subsystem = sdl.video().unwrap();
    let window = video_subsystem
        .window("Game", 800, 600)
        .opengl()
        .resizable()
        .build()
        .unwrap();
    // Context.
    let _gl_context = window.gl_create_context().unwrap();
    // Function point to drive.
    let _gl =
        gl::load_with(|s| video_subsystem.gl_get_proc_address(s) as *const std::os::raw::c_void);
    // Color.
    unsafe {
        gl::ClearColor(0.3, 0.3, 0.5, 1.0);
    }
    // Event loop.
    let mut event_pump = sdl.event_pump().unwrap();
    'main: loop {
        for event in event_pump.poll_iter() {
            match event {
                sdl2::event::Event::Quit { .. } => break 'main,
                _ => {}
            }
        }
        unsafe {
            gl::Clear(gl::COLOR_BUFFER_BIT);
        }
        window.gl_swap_window();
    }
}
